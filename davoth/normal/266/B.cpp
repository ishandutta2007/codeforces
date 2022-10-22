#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n,t;
    string s,s1;
    cin>>n>>t>>s;
    s1=s;
    while(t){
        for(int i=0;i<n;i++){
            if(s[i]=='B'&&s[i+1]=='G'){
                s1[i]='G';
                s1[i+1]='B';
            }
        }
        t--;
        s=s1;
    }
    cout<<s;
    return 0;
}