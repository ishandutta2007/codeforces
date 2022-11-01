#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;
struct qq
{
   long st, fi, we;
};
bool cmp(qq a, qq b)
{
    return a.we < b.we || (a.we == b.we && a.st < b.st ) ||
        (a.we == b.we && a.st == b.st && a.fi < b.fi);
}
typedef long long ll;
vector <qq> edge;
vector <long long> pr, pr1;
long  mi, n, k, mil;

long root(int nu)
{
    if(pr[nu] == nu)return nu;
    return pr[nu] = root(pr[nu]);
}
void merge(long nu, long nu1)
{
    if(rand() % 2)
    {
        pr[root(nu)] = root(nu1);
    }
    else pr[root(nu1)] = root(nu);
}
int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    pr.resize(n);
    pr1.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mil;
        pr[i] = i;
        pr1[i] = i;
    }
    cin >> k;
    qq pq;
    for(long i = 0; i < k; i++)
    {
        cin >> pq.st >> pq.fi >> pq.we;
        pq.st --;
        pq.fi --;
        edge.push_back(pq);
    }
    sort(edge.begin(), edge.end(), cmp);
    mi = 0;
    for(int i = 0; i < edge.size(); i++)
    {
        if(pr1[edge[i].fi] == edge[i].fi)
        {
            mi += edge[i].we;
            pr1[edge[i].fi] = edge[i].st;
            //merge(edge[i].st, edge[i].fi);
            //cout << edge[i].st << " " << edge[i].fi << endl;
        }
    }
    long long kou = 0;
    for(int i = 0; i < n; i++)
    {
        if(pr1[i] == i)
        {
            kou ++;

        }
    }
    if(kou > 1)cout <<-1;
    else cout << mi << endl;
    return 0;
}