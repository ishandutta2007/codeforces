#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long l=0,r=0;
    long long re=0;
    vector<long long> ls,rs;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='o'){
            ls.push_back(l);
        }else if(s[i]=='v' && s[i+1]=='v') l++;
    }
    for(int i=s.size()-2; i>=0; i--){
        if(s[i]=='o'){
            rs.push_back(r);
        }else if(s[i]=='v' && s[i+1]=='v') r++;
    }
    for(int i=0; i<ls.size(); i++){
        re+=rs[ls.size()-i-1]*ls[i];
    }
    cout << re;
    return 0;
}