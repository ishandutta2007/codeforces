#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N];int n;bool fl=0;
vector<int>v;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1,k=0;i<=n;i++)
        if(s[i]=='(')k=1;
        else if(k)fl=1;
    if(!fl)puts("0"),exit(0);
    for(int i=1,j=n;;){
        while(i<=j&&s[i]==')')i++;
        while(i<=j&&s[j]=='(')j--;
        if(i>j)break;
        v.push_back(i);i++;
        v.push_back(j);j--;
    }
    sort(v.begin(),v.end());puts("1");
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)printf("%d ",v[i]);
    return 0;
}