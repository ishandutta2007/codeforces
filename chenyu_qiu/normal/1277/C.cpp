#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void work()
{
    char a[2000005];
    scanf("%s",a+1);
    int l=strlen(a+1);
    vector<int>v;
    for(int i=1;i<=l-2;i++){
        if(a[i]=='o'&&a[i+1]=='n'&&a[i+2]=='e'){
            if(v.size()>0&&v[v.size()-1]==i){	//o
                continue;
            }else{
                v.push_back(i+1);
            }
        }
        if(a[i]=='t'&&a[i+1]=='w'&&a[i+2]=='o'){
            if(i<l-2&&a[i+3]=='o')	//owotwone
                v.push_back(i+1);
            else v.push_back(i+2);
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    //T=1;
    while(T--){
        work();
    }
}