#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct el
{
    int v, to, ne=-1;
};
struct el2
{
    int pr, sum=1, st=-1, en=-1;
};
int n;
vector <int> *sv1, *sv2;
vector <int*> del;
vector <el> re;
el2 *dsu;
int find_set(int v)
{
    if(dsu[v].pr==v) return v;
    else
    {
        int v2=find_set(dsu[v].pr);
        dsu[v].pr=v2;
        return v2;
    }
}
void unite(int v1, int v2)
{
    int s1=find_set(v1), s2=find_set(v2);
    if(s1!=s2)
    {
        if(dsu[s1].sum<dsu[s2].sum) swap(s1, s2);
        dsu[s1].sum+=dsu[s2].sum;
        dsu[s2].pr=s1;
        if(dsu[s1].st==-1)
        {
            dsu[s1].st=dsu[s2].st, dsu[s1].en=dsu[s2].en;
        }
        else
        {
            int pren=dsu[s1].en;
            re[pren].ne=dsu[s2].st;
            if(dsu[s2].en!=-1) dsu[s1].en=dsu[s2].en;
        }
    }
}
void dfs(int v, int pr, bool ty)
{
    int yk=0;
    for(int a=0; a<sv1[v].size(); a++)
    {
        int ne=sv1[v][a];
        if(ne!=pr)
        {
            bool fo=0;
            while(yk<sv2[v].size())
            {
                if(sv2[v][yk]<ne) yk++;
                else
                {
                    if(sv2[v][yk]==ne) fo=1;
                    break;
                }
            }
            dfs(ne, v, fo);
        }
    }
    if(pr!=-1)
    {
        if(ty) unite(v, pr);
        else
        {
            del.push_back(new int[2]);
            del.back()[0]=v, del.back()[1]=pr;
        }
    }
}
int main()
{
    ifstream in("input.txt");
    scanf("%d", &n);//in>>n;
    sv1=new vector <int> [n], sv2=new vector <int> [n], dsu=new el2[n];
    for(int a=0; a<n; a++) dsu[a].pr=a;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v); //in>>u>>v;
        u--, v--;
        sv1[u].push_back(v), sv1[v].push_back(u);
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v); //in>>u>>v;
        u--, v--;
        sv2[u].push_back(v), sv2[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        sort(sv1[a].begin(), sv1[a].end());
        sort(sv2[a].begin(), sv2[a].end());
        dsu[a].st=re.size();
        for(int b=0; b<sv2[a].size(); b++)
        {
            int ne=sv2[a][b];
            if(b!=0) re.back().ne=re.size();
            el *nel=new el;
            re.push_back(*nel);
            re.back().v=a, re.back().to=ne;
        }
        dsu[a].en=re.size()-1;
    }
    dfs(0, -1, 0);
    printf("%d", del.size()); //cout<<del.size();
    for(int a=0; a<del.size(); a++)
    {
        int s1=find_set(del[a][0]);
        while(1==1)
        {
            int cu=dsu[s1].st, s2, s3;
            s2=find_set(re[cu].v), s3=find_set(re[cu].to);
            if(s2!=s3)
            {
                printf("\n%d %d %d %d", del[a][0]+1, del[a][1]+1, re[cu].v+1, re[cu].to+1); //cout<<"\n"<<del[a][0]+1<<" "<<del[a][1]+1<<" "<<re[cu].v+1<<" "<<re[cu].to+1;
                unite(s2, s3);
                break;
            }
            else dsu[s1].st=re[cu].ne;
        }
    }
}