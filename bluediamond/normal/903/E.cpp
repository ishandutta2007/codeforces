#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2500;
const int L=5000;

int n,len;
string a[N+5];

int cnt_dif=0;
int dif[10];

int ap[30];

string b[N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>len;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=a[i];
        sort(b[i].begin(),b[i].end());
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if(b[1]!=b[n]) {
        cout<<"-1\n";
        return 0;
    }
    if(a[1]==a[n]) {
        swap(a[1][0],a[1][1]);
        cout<<a[1]<<"\n";
        return 0;
    }
    string x=a[1];
    string y=a[n];
    for(int i=0;i<len;i++) {
        if(x[i]!=y[i]) {
            dif[++cnt_dif]=i;
            if(cnt_dif>4) {
                cout<<"-1\n";
                return 0;
            }
        }
    }
    bool diferite=1;
    for(int i=0;i<len;i++) {
        int val=a[1][i]-'a';
        ap[val]++;
        if(ap[val]>=2) {
            diferite=0;
            break;
        }
    }
    for(int i=1;i<=cnt_dif;i++) {
        int p1=dif[i];
        for(int p2=0;p2<len;p2++) {
            if(p1==p2)
                continue;
            swap(a[1][p1],a[1][p2]);
            bool ok=1;
            for(int j=2;j<=n;j++) {
                int diff=0;
                for(int p=0;p<len;p++) {
                    if(a[1][p]!=a[j][p]) {
                        diff++;
                        if(diff>2) {
                            break;
                        }
                    }
                }
                if(diff==2)
                    continue;
                if(diff==0 && diferite==0)
                    continue;
                ok=0;
                break;
            }
            if(ok==1) {
                cout<<a[1]<<"\n";
                return 0;
            }
            swap(a[1][p1],a[1][p2]);
        }
    }
    cout<<"-1\n";
    return 0;
}
/**

**/