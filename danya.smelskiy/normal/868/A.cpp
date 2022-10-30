#include <bits/stdc++.h>
using namespace std;

string s;
string ss[1005];
int n;
vector<int> v1,v2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>ss[i];
        if (ss[i]==s){
            cout<<"YES";
            return 0;
        }
        if (ss[i][0]==s[1] && v1.size()<2) {
            v1.push_back(i);
        }
        if (ss[i][1]==s[0] && v2.size()<2) {
            v2.push_back(i);
        }
    }
    if (v1.size() && v2.size()) cout<<"YES";
    else cout<<"NO";

}