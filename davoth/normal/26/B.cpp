#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main()
{
    string s;
    cin >> s;
    int cnt=0,r=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') cnt++;
        else{
            if(cnt){
                r++;
                cnt--;
            }
        }
    }
    cout << r*2;
    return 0;
}