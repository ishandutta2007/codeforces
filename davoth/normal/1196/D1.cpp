#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string an;
    for(int i=0; i<t; i++) {
        int n,k,a=0,b=0,c=0,e=0,f=0,g=0,m=999999;
        string s;
        cin >> n >> k >> s;
        char d[]={'R','G','B'};
        for(int j=0; j<n; j++){
            a=0;
            c=2;
            b=1;
            e=0;
            f=0;
            g=0;
            for(int o=j; o<n; o++){
                if(s[o]==d[a%3]){
                    a++;
                }else{
                    e++;
                    a++;
                }
                if(s[o]==d[b%3]){
                    b++;
                }else{
                    f++;
                    b++;
                }
                if(s[o]==d[c%3]){
                    c++;
                }else{
                    g++;
                    c++;
                }
                if(a==k){
                    if(e<m) m=e;
                }
                if(b-1==k){
                    if(f<m) m=f;
                }
                if(c-2==k){
                    if(g<m) m=g;
                }
            }
        }
        an+=to_string(m);
        an+='\n';
    }
    cout << an;
    return 0;
}