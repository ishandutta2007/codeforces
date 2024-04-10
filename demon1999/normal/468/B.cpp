#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
long m, i, j, k, n, a, b, l, r, p1[2][100001], q[100001];
vector <pair<long, long> > p, s1;
pair <long, long> a1;
vector <long> i1;
bool dfs(long num, long n1)
{
	if(num == -1)return true;
    q[num] = n1;
    if(p1[n1][num] == -1) 
    {
     return false;
    }
    i1.push_back(num);
    i1.push_back(p1[n1][num]);
    q[p1[n1][num]] = n1;
    if((p1[(n1 + 1) % 2][num] > -1 && q[p1[(n1 + 1) % 2][num]] == -1 && !dfs(p1[(n1 + 1) % 2][num], n1)) || 
		(p1[(n1 + 1) % 2][p1[n1][num]] > -1 && q[p1[(n1 + 1) % 2][p1[n1][num]]] == -1 && !dfs(p1[(n1 + 1) % 2][p1[n1][num]], n1)))
    return false;
    return true;
}

int main()
{
    cin >> n >> a >> b;
    for(i = 0; i < n; i++)
    {
        cin >> m;
		a1.first = m;
		a1.second = i;
        p.push_back(a1);
    }
    sort(p.begin(), p.end());
    for(i = 0; i < n; i++)
    {
        q[i] = -1;
        p1[0][i] = -1;
        p1[1][i] = -1;
        l = 0; r = n;
        while(r - l > 1)
        {
            m = (l + r)  / 2;
            if(p[m].first > a - p[i].first) r = m;
                else l = m;
        }

        if(a - p[i].first == p[l].first)p1[0][i] = l;
        l = 0; r = n;
        while(r - l > 1)
        {
            m = (l + r)  / 2;
            if(p[m].first > b - p[i].first) r = m;
                else l = m;
        }
        if(b - p[i].first == p[l].first)p1[1][i] = l;
    }
    for(i = 0; i < n; i++)
    {
        if(q[i] != -1) continue;
        i1.resize(0);
        if(!dfs(i, 0))
        {
            for(j = 0; j <i1.size(); j++)q[i1[j]] = -1;      
            if(!dfs(i, 1))
            {
                cout << "NO";
                return 0;
            }
        }
    }
	for(i = 0; i < n; i++)
	{
		a1.first = p[i].second;
		a1.second = q[i];
		s1.push_back(a1);
	}
	sort(s1.begin(), s1.end());
    cout << "YES" << endl;
    for(i = 0; i < n; i++)
        cout << s1[i].second << " ";
    return 0;
}