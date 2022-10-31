#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

struct mat{
    long long m[2][2];
}ans,res;
void init(mat &a)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            if(i==j)    a.m[i][j]=1;
            else a.m[i][j]=0;
        }
}
mat mul(mat a,mat b)
{
    mat temp;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            temp.m[i][j]=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                {
                    temp.m[i][j]+=a.m[i][k]*b.m[k][j];
                    temp.m[i][j]%=mod;
                }
    return temp;
}
mat quick_pow(long long b)
{
    init(ans);
    while(b)
    {
        if(b&1) ans=mul(ans,res);
        res=mul(res,res);
        b>>=1;
    }
    return ans;
}
int main()
{
    long long n;
    cin>>n;
    res.m[0][0]=3;
    res.m[0][1]=1;
    res.m[1][0]=1;
    res.m[1][1]=3;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<3<<endl;
        return 0;
    }
    quick_pow(n);
    cout<<(ans.m[0][0])%mod<<endl;
    return 0;

}