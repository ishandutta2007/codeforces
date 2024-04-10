#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
string trin(ll a){
    string s;
    while(a>0){
        char c='0'+(a%3);
        string cs="";
        cs+=c;
        s.insert(0,cs);
        a/=3;
    }
    return s;
}
int main()
{
    int q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        string s=trin(n);
        int pos=-1;
        bool cp=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='0') pos=max(i,pos);
            else if(s[i]=='2'){
                pos=-1;
                cp=1;
            }
        }
        if(cp==0){
            cout << n << '\n';
            continue;
        }
        if(pos==-1){
            cout << (ll)pow(3,s.size()) << '\n';
        }else{
            ll sol=0;
            s[pos]='1';
            for(int i=pos+1; i<s.size(); i++){
                s[i]='0';
            }
            for(int i=0; i<s.size(); i++){
                sol+=pow(3,s.size()-i-1)*(ll)(s[i]-'0');
            }
            cout << sol << '\n';
        }
    }
	return 0;
}