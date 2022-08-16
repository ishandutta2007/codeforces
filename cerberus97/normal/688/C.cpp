#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

long long color1[100001]={0};
bool check[100001]={false};
int checkcount=0;
vector <long long> graph[100001];
long long f=0;

void bfs(long long start)
{
    queue <long long> q;
    q.push(start);
    while(q.size()!=0)
    {
           check[q.front()]=true;
           long long temp=color1[q.front()];
           long long temp2;
           if(temp==1)
                temp2=2;
           else if(temp==2)
                temp2=1;
           vector <long long> :: iterator it;
           for(it=graph[q.front()].begin();it!=graph[q.front()].end();it++)
           {
               if(check[*it]==false)
               {
                   if(color1[*it]==temp)
                        f=1;
                   else
                   {
                       color1[*it]=temp2;
                       q.push(*it);
                   }

                   check[*it]=true;
               }

               else
               {
                   if(color1[*it]==temp)
                        f=1;
               }
           }
           checkcount++;
           q.pop();
    }
}

int main()
{

    long long num_nodes,num_edge;
    cin>>num_nodes>>num_edge;
    for(long long i=0;i<num_edge;i++)
    {
        long long x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    color1[1]=1;
    bfs(1);
    while(checkcount<num_nodes)
    {
        for(int i=2;i<=num_nodes;i++)
        {
            if(check[i]==false)
            {
                color1[i]=1;
                bfs(i);
            }
        }
    }
    if(f==1)
        cout<<"-1"<<endl;
    else
    {
        long long a[100001];
        long long a1,b1;
        a1=0;
        b1=0;
        long long b[100001];
        for(long long i=1;i<=num_nodes;i++)
        {
            if(color1[i]==1)
            {
                a[a1]=i;
                a1++;
            }
            else if(color1[i]==2)
            {
                b[b1]=i;
                b1++;
            }
        }
        cout<<a1<<endl;
        for(long long i=0;i<a1;i++)
            cout<<a[i]<<' ';
        cout<<endl;
        cout<<b1<<endl;
        for(long long i=0;i<b1;i++)
            cout<<b[i]<<' ';
        cout<<endl;
    }

    return 0;
}