//  228

/*
 *    author:    Apiram
 *    created:   04.04.2021 12:58:02
*/
 
#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int64_t n,m,a,b;
cin>>n>>m>>a>>b;
--a;--b,--n;
int64_t last=b/m ;
int64_t first=a/m ;
int temp1=a%m;
int temp2=b%m;
//if (temp1==0)temp1=m;
//if (temp2==0)temp2=m;
//int64_t counts=3;
//if ((a-1)%m==0&&last-first!=1)counts--;
//if ((b==n&&(last-first!=1))||b%m==0)counts--;
//if (last-first==1)counts--;
//cout<<first<<" "<<last;

//if (temp1==m&&temp2==m){
//    cout<<1<<endl;
//}
//else if (temp1==m)cout<<2<<endl;
if ((first==last)||(temp1==0&&b==n)||(temp1==0&&(temp2==m-1)))cout<<1;
else if (last-first==1||temp1==0||temp2==m-1||b==n||temp1-temp2==1)cout<<2;
else cout<<3;
return 0;}