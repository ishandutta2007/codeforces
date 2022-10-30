#include <bits/stdc++.h>
using namespace std;


int n;
string s;
int nxt[100];
int pred[100];
string ans;
bool used2[100];
bool used[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        for (int j=0;j<s.size();++j) {
            used2[s[j]-'a'+1]=true;
            if (j) {
                int x=s[j-1]-'a'+1;
                int y=s[j]-'a'+1;
                if (x==y || (nxt[x] && nxt[x]!=y)) {
                    cout<<"NO";
                    return 0;
                }
                if (pred[y] && pred[y]!=x) {
                    cout<<"NO";
                    return 0;
                }
                nxt[x]=y;
                pred[y]=x;
            }
        }
    }
    for (int i=1;i<=26;++i)
    if (used2[i] && !pred[i]) {
        int x=i;
        while (x) {
            if (used[x]) {
                cout<<"NO";
                return 0;
            }
            used[x]=true;
            ans+=char(x+'a'-1);
            x=nxt[x];
        }
    }
    for (int i=1;i<=26;++i)
    if (used2[i] && !used[i]) {
        cout<<"NO";
        return 0;
    }
    cout<<ans;
}