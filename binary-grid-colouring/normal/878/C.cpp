#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int w,a[50005][12],b[50005][12],s[50005];
set<pair<int,int> >q[12];
int main()
{
    cin>>n>>k;
    vector<int>ans(n+1);
    for(int i=1;i<=k;i++)
	{
    	scanf("%d",a[1]+i);
		b[1][i]=a[1][i];
		s[1]=1;
	}
    w=1;
    ans[1] = 1;
    for(int i=2;i<=n;i++)
	{
        for(int j=1;j<=k;j++)
		{
            scanf("%d",a[i]+j);
			b[i][j]=a[i][j];
			s[i]=1;
		}
        bool flag = true;
        for(int j=1;j<=k;j++)
		{
           	if(a[i][j]<b[w][j]){
            	flag = false;
			}
		}
        if(flag)
		{
            for(int j=1;j<=k;j++)
			{
				q[j].insert(make_pair(-b[w][j],w));
			}
            w=i;
        }
        else
		{
            flag = true;
            for(int j=1;j<=k;j++)
			{
				q[j].insert(make_pair(-b[i][j],i));
			}
            while(flag)
			{
                flag = false;
                for(int j=1;j<=k;j++)
				{
                    if(q[j].empty()) continue;
                                   
                    if(-(q[j].begin()->first) < a[w][j]) continue;
                                   
                    int x=q[j].begin()->second;
                                   
                    for(int l=1;l<=k;l++)
					{
						q[l].erase(make_pair(-b[x][l],x));
					}
                    for(int l=1;l<=k;l++)
					{
						a[w][l]=min(a[w][l],a[x][l]);
						b[w][l]=max(b[w][l],b[x][l]);
					}
                   	s[w] += s[x]; 
                    flag = true;
                    break;
                }
            }
        }
        ans[i] = s[w];
        
    }
    for(auto x:ans)
    {
    	if(x==0)continue;
    	cout<<x<<endl;
	}
	return 0;
}