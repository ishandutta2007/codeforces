#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int l[28]={0};
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(l[s[i]-97]==0){
            l[s[i]-97]=1;
            cnt++;
        }
    }
    if(cnt%2==0){
        cout<<"CHAT WITH HER!";
    }else{
        cout<<"IGNORE HIM!";
    }
    return 0;
}