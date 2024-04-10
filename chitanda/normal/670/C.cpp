#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
int a[200005];
struct mo{
	int b;
	int c;
	int i;
};
mo f[200005];

mo ans[200005];
int main()
{
    int n,m;
   // freopen("1.txt","r",stdin);
    while(~scanf("%d",&n)){

    	map<int,int>mp;
         for(int i=1;i<=n;i++){
        	 scanf("%d",&a[i]);
             mp[a[i]]++; 
         }
         scanf("%d",&m);
         for(int i=1;i<=m;i++){
        	 scanf("%d",&f[i].b);
             f[i].i=i;
         }
         for(int i=1;i<=m;i++)
        	 scanf("%d",&f[i].c);

         int pos=1;
         int num=-1;
         for(int i=1;i<=m;i++){
//        	 printf("%d %d %d %d\n",i,f[i].b,f[i].c,mp[f[i].b]);
        	 if(mp[f[i].b]>num){
//        		 printf("%d\n",i);
        		 pos=1;
        		 num=mp[f[i].b];
        		 ans[pos]=f[i];
        		 pos++;
        	 }
        	 else if(mp[f[i].b]==num){
        		 ans[pos]=f[i];
        		 pos++;
        	 }
         }
//         printf("pos=%d\n",pos);
         num=-1;
         int cnt;
         for(int i=1;i<pos;i++){
//        	 printf("%d %d %d\n",ans[i].i,ans[i].b,ans[i].c);
        	 if(mp[ans[i].c]>=num){
        		 cnt=ans[i].i;
        		 num=mp[ans[i].c];
        	 }
         }
         printf("%d\n",cnt);
    }
}