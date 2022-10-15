#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool no[30];
bool all[30];
bool g[30];
int n;
string t,a;
bool over=0;
int shock=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<26;i++) {
        all[i]=1;
    }
    for(int i=1;i<=n;i++) {
        cin>>t>>a;
        if(t==".") {
            for(auto itr:a) {
                no[itr-'a']=1;
            }
        }
        if(t=="!") {
            if(over) {
                shock++;
            }
            for(int j=0;j<26;j++) {
                g[j]=0;
            }
            for(auto itr:a) {
                g[itr-'a']=1;
            }
            for(int j=0;j<26;j++) {
                all[j]*=g[j];
            }
        }
        if(t=="?") {
            if(i!=n) {
                if(over) {
                    shock++;
                }
                no[a[0]-'a']=1;
            }
        }
        if(over) {
            continue;
        }
        int cnt=0;
        for(int j=0;j<26;j++) {
            if(no[j] || all[j]==0) {
                continue;
            }
            cnt++;
        }
        if(cnt==1) {
            over=1;
        }
    }
    cout<<shock<<"\n";
    return 0;
}

/**

a b
a c

**/