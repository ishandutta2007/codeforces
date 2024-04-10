#include <bits/stdc++.h>
using namespace std;

int main() {
    int a['z'-'a'+1]={0},cnt=0;
    string s;
    getline(cin, s);
    if(s.size()!=2){
        for(int i=1; i<s.size(); i+=3){
            if(a[s[i]-'a']==0){
                cnt++;
                a[s[i]-'a']=1;
            }
        }
    }
    cout << cnt;
    return 0;
}