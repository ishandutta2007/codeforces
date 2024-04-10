#include<stdio.h>
#include<vector>
using namespace std;

#define MAX(A, B) ((A)>(B)?(A):(B))
#define MIN(A, B) ((A)<(B)?(A):(B))

vector< vector<int> > V;
vector<int> adj[100005];
int common[100015];
int n;

int nBIT[100015], nBIT_sz[100015], nBIT_POS[100015];

void buildgraph()
{
	int sz, i, par, cnt, now, sz1, temp;

	sz = adj[1].size();
	for(i = 0; i < sz; i++)
	{
//		vector<int> Z;


		cnt = 0;
		par = 1;
		now = adj[1][i];
//		Z.push_back(now);
		nBIT[now] = i;
		nBIT_POS[now] = ++cnt;

		while(1)
		{
			sz1 = adj[now].size();
			if(sz1==1) break;
			
			temp = now;
			if(par == adj[now][0])
				now = adj[now][1];
			else
				now = adj[now][0];

//			Z.push_back(now);
			par = temp;
			nBIT[now] = i;
			nBIT_POS[now] = ++cnt;
		}

		nBIT_sz[i] = cnt;

		vector<int> Z(cnt+1,0);
		V.push_back(Z);
	}

}


//return cf[idx]
int readIndiv(int tree_id, int idx)
{
	int sum = 0;

	while (idx > 0)
	{
		sum += V[tree_id][idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void updateIndiv(int tree_id, int idx ,int val)
{
	while (idx <= nBIT_sz[tree_id])
	{
		V[tree_id][idx] += val;
		idx += (idx & -idx);
	}
}


//return cf[idx]
int readCommon(int idx)
{
	int sum = 0;

	while (idx > 0)
	{
		sum += common[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void updateCommon(int idx ,int val)
{
	while (idx <= n+10)
	{
		common[idx] += val;
		idx += (idx & -idx);
	}
}



int main()
{
	int q, i, v, x, d, cmd;
	int u, len,ans;
	int branch_id, position, size_tree;

	scanf("%d%d", &n, &q);

	for(i = 0; i < n-1; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	buildgraph();

	while(q--)
	{
		scanf("%d", &cmd);

		if(cmd==0)
		{
			scanf("%d%d%d",&v,&x,&d);

			if(v==1)
			{
				updateCommon(1, x);
				updateCommon(MIN(d+2, n+1), -x);
			}
			else
			{
				branch_id = nBIT[v];
				position  = nBIT_POS[v];
				size_tree = nBIT_sz[branch_id];

				updateIndiv(branch_id, MAX(1, position-d), x);
				updateIndiv(branch_id, MIN(position+d+1, size_tree+1), -x);

				if(position-d<=0)
				{
					len = d - position + 1;
					updateCommon(1, x);
					updateCommon(MIN(len+1, n+1), -x);

					updateIndiv(branch_id, 1, -x);
					updateIndiv(branch_id, MIN(len, size_tree+1), x);
				}
			}
		}
		else
		{
			scanf("%d", &v);

			if(v==1)
				ans = readCommon(1);
			else
			{
				branch_id = nBIT[v];
				position  = nBIT_POS[v];
				size_tree = nBIT_sz[branch_id];

				ans = readCommon(position+1);
				ans += readIndiv(branch_id, position);
			}

			printf("%d\n", ans);
		}
	}


	return 0;
}