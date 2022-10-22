#include <iostream>
using namespace std;
int main(){
    int n,k,c=0,first[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},last[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s;
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        last[s[i]-65]=i;
    }
    for(int i=n-1;i>=0;i--){
        first[s[i]-65]=i;
    }
    for(int i=0;i<n;i++){
        if(first[s[i]-65]==i){
            c++;
        }
        if(c>k){
            cout<<"YES";
            return 0;
        }
        if(last[s[i]-65]==i){
            c--;
        }
    }
    cout<<"NO";
    return 0;
}