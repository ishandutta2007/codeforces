#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    map<char,int> m;
    m['>']=8;m['<']=9;m['+']=10;m['-']=11;
    m['.']=12;m[',']=13;m['[']=14;m[']']=15;
    string c;
    cin>>c;
    int s=0;
    for(int i=0;i<c.length();i++){
        s=s*16+m[c.at(i)];
        s%=1000003;
    }
    cout<<s;
}