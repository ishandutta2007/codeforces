#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[4];
char oper[4];
ll cal(ll a,ll b,char o)
{  
    if(o=='+')return a+b;  
    if(o=='*')return a*b;  
}  
int main()  
{  
    scanf("%lld%lld%lld%lld",&num[0],&num[1],&num[2],&num[3]);  
    getchar();  
    scanf("%c %c %c",&oper[0],&oper[1],&oper[2]);  
    int id[5];
    ll ans = 999999999999999999;
	id[0]=0;id[1]=1;id[2]=2;id[3]=3;  
    do  
    {  
        ll a=cal(num[id[0]],num[id[1]],oper[0]);  
        
        ll b=cal(a,num[id[2]],oper[1]); 
		 
        ll temp=cal(b,num[id[3]],oper[2]);  
        
        a=cal(num[id[0]],num[id[1]],oper[0]);  
        
        b=cal(num[id[2]],num[id[3]],oper[1]);  
        
        ll temp1=cal(a,b,oper[2]);  
        
        ans=min(ans,min(temp,temp1));  
        
    }while(next_permutation(id,id+4));  
    printf("%lld\n",ans);  
    return 0;  
}