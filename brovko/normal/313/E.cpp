#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector <int> cnta(N), cntb(N);
    bitset <N> ba, bb;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        cnta[x]++;
        ba[x] = 1;
    }
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        x = (m - x) % m;
        
        cntb[x]++;
        bb[x] = 1;
    }
    
    bitset <N> bc;
    
    for(int i = m - 1; i >= 0; i--)
    {
        bool last = bb[0];
        bb >>= 1;
        bb[m - 1] = last;
        
        bc = (ba & bb);
        
        for(int j = bc._Find_first(); j < m; j = bc._Find_next(j))
        {
            int bj = (j + m - i) % m;
            
            while(cnta[j] && cntb[bj])
            {
                cnta[j]--;
                cntb[bj]--;
                
                cout << i << ' ';
                
                if(cnta[j] == 0)
                {
                    ba[j] = 0;
                    bc[j] = 0;
                }
                
                if(cntb[bj] == 0)
                {
                    bb[j] = 0;
                    bc[j] = 0;
                }
            }
        }
    }
}