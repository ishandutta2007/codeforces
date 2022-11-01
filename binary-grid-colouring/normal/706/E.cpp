#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1234
struct DLX
{
    int v, U, D, L, R;
}a[N*N];
int n, m, q;

void init()
{
    int L1, L2, L3, L4;
    L1 = n + n + m + m;
	L2 = n + n * m;
	L3 = 2 * n + m;
	L4 = n + m - 1;
    for(int i = 1; i <= n * m; i++) 
	{
		scanf("%d", &a[i + L1].v);
	}
    for(int i = L1 + 1; i <= L1 + n * m; i++){
    	a[i].L = i - 1;
		a[i].R = i + 1;
		a[i].U = i - m;
		a[i]. D = i + m; 
	}
        
    for(int i = L1 + 1; i <= L1 + m; i++){
    	a[i - L1].D = i;
		a[i].U = i - L1;
	}
        
    for(int i = L1 + n * m - m + 1; i <= L1 + n * m; i++)
    {
    	a[i - L2].U = i;
		a[i].D = i - L2;
	}
        
    for(int i = L1 + 1; i <= L1 + n * m; i += m)
    {
    	a[i - L3].R = i;
		a[i].L = i - L3;
		L3 += m - 1;
	}
        
    for(int i = L1 + m; i <= L1 + n * m; i += m){
    	a[i - L4].L = i;
		a[i].R = i - L4;
		L4 += m - 1;
	}
        
}

void output()
{
    for(int i = m + 1; i <= n + m; i++)
	{
        int nw = a[i].R;
        while (nw != i + n + m) 
		{
			printf("%d ", a[nw].v);
			nw = a[nw].R;
		}
        printf("\n");
    }
}

int Down(int p, int s)
{
    while (s--) p = a[p].D;
    return p;
}

void work()
{
    int x1, y1, x2, y2, h, w, p1, p2, s, t1, t2;
    
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
    
    p1 = Down(y1, x1);
	p2 = Down(y2, x2), s = w;
    while (s--)
	{
        t1 = a[p1].U, t2 = a[p2].U;
        a[p1].U = t2, a[p2].U = t1;
        a[t1].D = p2, a[t2].D = p1;
        p1 = a[p1].R, p2 = a[p2].R;
    }
    p1 = a[p1].L, p2 = a[p2].L, s = h;
    while (s--)
	{
        t1 = a[p1].R, t2 = a[p2].R;
        a[p1].R = t2, a[p2].R = t1;
        a[t1].L = p2, a[t2].L = p1;
        p1 = a[p1].D, p2 = a[p2].D;
    }
    p1 = a[p1].U, p2 = a[p2].U, s = w;
    while (s--)
	{
        t1 = a[p1].D, t2 = a[p2].D;
        a[p1].D = t2, a[p2].D = t1;
        a[t1].U = p2, a[t2].U = p1;
        p1 = a[p1].L, p2 = a[p2].L;
    }
    p1 = a[p1].R, p2 = a[p2].R, s = h;
    while (s--)
	{
        t1 = a[p1].L, t2 = a[p2].L;
        a[p1].L = t2, a[p2].L = t1;
        a[t1].R = p2, a[t2].R = p1;
        p1 = a[p1].U, p2 = a[p2].U;
    }
}

int main()
{
    cin >> n >> m >> q;
    init();
    for(int i = 1; i <= q; i++) work();
    output();
    return 0;
}