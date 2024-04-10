#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
char s[maxn];
int a,b;
int main(){
    scanf("%s",s);
    int n = strlen(s);
    for (int i=0;i<n;i++){
        a+=s[i]=='o';
        b+=s[i]=='-';
    }
   // cout<<a<<" "<<b<<endl;
    if (a<=1||b==0||b%a==0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}