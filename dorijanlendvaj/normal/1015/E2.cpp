#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned long long
#define sz(v)  ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
#define db(x) cout << " WHY " <<  x << '\n'
#define MEM(dp,i) memset( dp ,i, sizeof (dp))
#define forr(c,x,n)   for( int c=x;c<=(int)n; ++c)
#define forrr(c,x,n)  for(int c=x;c>=( int )n ;--c)
#define ICPC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int n , m , c[1007][1007] , r[1007][1007];
vector<pair<pair<int,int> , int>  >v;
char arr[1007][1007];
int lastn[1007][1007],nxtn[1007][1007] , lastm[1007][1007],nxtm[1007][1007];
int main()
{
   ICPC;
   cin >> n >> m ;

  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
      cin >> arr[i][j];

	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='.')
			{
				cnt=0;
				continue;
			}
			lastm[i][j]=cnt;
			cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=m-1;j>=0;j--)
		{
			if(arr[i][j]=='.')
			{
				cnt=0;
				continue;
			}
			nxtm[i][j]=cnt;
			cnt++;
		}
	}
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(arr[j][i]=='.')
			{
				cnt=0;
				continue;
			}
			lastn[i][j]=cnt;
			cnt++;
		}
	}
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			if(arr[j][i]=='.')
			{
				cnt=0;
				continue;
			}
			nxtn[i][j]=cnt;
			cnt++;
		}
	}

   for(int i=0;i<n;i++)
  {for(int j=0;j<m;j++)
  {
             if ( arr[i][j] == '.' )
				continue;
  	        int ln = min(min(lastn[j][i],nxtn[j][i]),min(lastm[i][j],nxtm[i][j]));
  	        if ( ln  )
			{
				v.push_back({ { i+1 , j+1 } , ln});
				r[i][j-ln]++;
				r[i][j+ln+1]--;
		        c[i - ln][j]++;
		        c[i+ln+1][j]--;
			}

  }
  }
  for ( int i = 0 ; i <  n ; i++ )
  {
  	for ( int j =1  ; j < m ; j++  )
		r[i][j]+= r[i][j-1];
  }
  for ( int i = 0 ; i <   m ; i++ )
  {
  	for ( int j =1  ; j < n  ; j++  )
		c[j][i]+= c[j-1][i];
  }

	 for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       if ( arr[i][j] =='*' && !( c[i][j] || r[i][j] ))
		   	return cout << -1 , 0 ;

	cout << v.size() << '\n';
	for ( auto i : v)
		cout << i.F.F << " " << i.F.S << " " << i.S << '\n';

}