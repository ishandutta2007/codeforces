#include<bits/stdc++.h>
using namespace std;


int n,m,k,ans,x,y,cnt,i;
int color[200010];
int par[200010],best[200010];

map<int,int> Ccount[200010];
vector<int> vec[200010];


int find_representative(int r)
{
    if(par[r] == r) return r;
    else
    {
        return par[r] = find_representative(par[r]);
    }
}

void Union(int c, int d)
{
    int u = find_representative(c);
    int v = find_representative(d);

    if(u!=v)
    {
        par[v] = u;
    }
}

void countbest()
{
	for(i=1; i<=n; i++)
	Ccount[find_representative(i)][color[i]]++;
	for(i=1; i<=n; i++)
	{
		if(par[i]==i)
		{
			best[i]=color[i];
			int max_count=0;
			for(map<int,int>::iterator it=Ccount[i].begin();it!=Ccount[i].end();it++)
			if(it->second>max_count){
				best[i]=it->first;
				max_count=it->second;
			}
		}
	}
}
int main()
{
    for(i = 0; i < 200010; i++)
    {
        par[i] = i;
        vec[i].clear();
    }

    cin>>n>>m>>k;

    for(i = 1; i <= n; i++)
        cin>>color[i];


    for(i = 1; i <= m; i++)
    {
        cin>>x>>y;
        vec[i].push_back(x);
        vec[i].push_back(y);
        Union(x,y);
    }

	countbest();

    for(i = 1; i <= m; i++)
    {
        x = vec[i][0];
        y = vec[i][1];

        //cout<<"x = "<<x<<"y = "<<y<<endl;

        int p = find_representative(x);
        int q = find_representative(y);
        if(p == q)
        {
            if(color[x]!=best[p])
            {
                color[x]=best[p];
                cnt++;
            }

            if(color[y]!=best[p])
            {
                color[y]=best[p];
                cnt++;
            }
        }
    }

    cout<<cnt;
}