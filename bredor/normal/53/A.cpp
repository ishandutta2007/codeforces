//  228

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    int tt=s.size();
    string s1;
    int len;
    string ans="";
    int m=0,k=0;
 string p;
    while(n--){
       cin>>s1;
       len=s1.size();
      int count=0;
         for(int i=0;i<len;i++){
               if(s[i]==s1[i]){
                   count++;
               }
              else{
                  break;
              }
           }
           if(ans.size()==0&&count==tt){
               ans=s1;
           }
       else if(count==tt&&ans>s1){
        ans=s1;
       }
       
    }
 if(ans.size()==0){
     cout<<s;
 }
 else{
     cout<<ans;
 }
    return 0;
}