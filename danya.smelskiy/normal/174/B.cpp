#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> q;
vector<string> ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='.') q.push_back(i);
        if (i && s[i-1]=='.' && s[i]=='.') {
            cout<<"NO";
            return 0;
        }
    }
    if (q.size()==0) {
        cout<<"NO";
        return 0;
    }
    string last="";
    for (int i=0;i<q[0];++i)
        last+=s[i];
    if (last.size()>8) {
        cout<<"NO";
        return 0;
    }
    for (int i=0;i<q.size();++i) {
        if (last.size()==0) {
            cout<<"NO";
            return 0;
        }
        last+=".";
        int x=q[i];
        if (i==q.size()-1) {
            if (x==s.size()-1 || s.size()-1-x>3) {
                cout<<"NO";
                return 0;
            }
            for (int j=x+1;j<s.size();++j)
                last+=s[j];
            ans.push_back(last);
            break;
        }
        int len=q[i+1]-1-q[i];
        if (len<=1 || len>11) {
            cout<<"NO";
            return 0;
        }
        if (len<=3) {
            ++x;
            last+=s[x];
            ans.push_back(last);
            last="";
            while ((++x)<q[i+1]) last+=s[x];
            continue;
        } else {
            for (int j=1;j<=3;++j){
                ++x;
                last+=s[x];
            }
            ans.push_back(last);
            last="";
            while ((++x)<q[i+1]) last+=s[x];
        }
    }
    cout<<"YES"<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<'\n';
}