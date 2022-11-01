#include<bits/stdc++.h>

using namespace std;
const int maxn = 300123;
const double eps = 1e-9;
const int mod = 1e9+7;
typedef long long ll;

ll qpower(long long a,ll b,ll mod)
{
    long long ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

int a[maxn];
char color[maxn];
int c[maxn];
int nodea ,nodeb,nodeaa,nodebb;
int num ;
ll result;
int main(int argc, char const *argv[]) {
  /* code */
  int n;
  std::cin >> n;
  for(int i=1;i<=n;i++)
  {
    std::cin >> a[i] >> color[i];
    if(color[i]=='G'){
      c[++num] = a[i];
    }
    if(color[i]=='R'){
      if(!nodea)
      {
        nodea=a[i];
      }
      nodeb = a[i];
    }
    if (color[i]=='B')
		{
			if (!nodeaa)
      {
        nodeaa=a[i];
      }
			nodebb=a[i];
		}
  }
  int res1 = 0,res2 = 0,tmp1 = 0,tmp2 = 0,tmp3 = 0;
  if(num>0)
	{
    //std::cout << "result= " << result << '\n';
		bool flag1=true,flag2=true;
	  for(int i=1;i<=n;i++){
      /* code */
      if(color[i]=='B')
  		{
  			if(a[i]<c[1] && flag1==true )
  			{
  				flag1=false;
          result += (c[1]-a[i]);
  			}
  			else if(a[i] > c[1])
  			{
  				res1 = max(res1,a[i]-tmp1);
  				tmp1 = a[i];
  			}
  		}
  		else if(color[i]=='R')
  		{
  			if(a[i] < c[1] && flag2 == true)
  			{
  				flag2 = false;
          result += (c[1]-a[i]);
  			}
  			else if(a[i]>c[1])
  			{
  				res2 = max(res2 , a[i] - tmp2);
  				tmp2 = a[i];
  			}
  		}
    //  std::cout << "/* message */" << '\n';
  		else if (a[i]==c[1])
      {
        res1 = res2 = 0;
        tmp1 = tmp2 = tmp3 = c[1];
      }
  		else
  		{
  			res1 = max(a[i] - tmp1, res1);
  			res2 = max(a[i] - tmp2, res2);
  			if (a[i] - tmp3 < res1+res2)
        {
          result += (3 * (a[i] - tmp3) - res1 - res2);
        }
        //std::cout << "result= " << result << '\n';
  			else {
          result += (2 * (a[i]-tmp3) );
        }
  			res1 = res2 = 0;
  			tmp1 = tmp2 = a[i];
        tmp3 = a[i];
  		}
    }
		result += (tmp1 + tmp2 - 2 * c[num]);
    //std::cout << "result= " << result << '\n';
	}
  else
	{
    	if(nodeaa){
        result += (nodebb - nodeaa);
      }
    	if(nodea){
        result += (nodeb - nodea);
      }
    //std::cout << "result= " << result << '\n';
	}
  std::cout << result << '\n';
  return 0;
}