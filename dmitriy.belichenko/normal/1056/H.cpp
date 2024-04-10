#include <bits/stdc++.h>
#pragma gcc optimize("Ofast" )
#pragma gcc target("sse4" , "sse2" , "sse3" , "avx") 
using namespace std;

const int N = 300001, K = 50;
unordered_map<long long, int> mp;

vector<int> c[N];
int pos[N];

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        mp.clear();
        fill(pos, pos + N, -1);
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < q; i++)
        {
//
            int k;
            scanf("%d", &k);
            c[i].resize(k);
            for(auto &x: c[i])
                scanf("%d", &x);
        }
        bool human = false;
        for(int i = 0; i < q; i++)
            if(c[i].size() <= K)
            {
                for(int j = 0; j < c[i].size(); j++)
                    for(int k = 0; k < j; k++)
                    {
                        auto &m = mp[((long long)c[i][k] << 30LL) | c[i][j]];
                        if(m == 0) m = c[i][k+1];
                        else if(m != c[i][k+1])
                        {
                            human = true;
                            goto end;
                        }
                    }
            }
            else
            {
                for(int j = 0; j < c[i].size(); j++)
                    pos[c[i][j]] = j;
                for(int j = 0; j < q; j++)
                    if(i != j)
                    {
                        //printf("%d %d: ", i, j);
                        int prev = n + 1;
                        bool com = false;
                        for(int x: c[j])
                        {
                            //printf("(%d %d) ", prev, pos[x]);
                            if(pos[x] == -1)
                                com = false;
                            else
                            {
                                if(pos[x] < prev || (com && pos[x] == prev + 1))
                                {
                                    prev = pos[x];
                                    com = true;
                                }
                                else
                                {
                                    human = true;
                                    goto end;
                                    break;
                                }
                            }
                        }
                        //puts("");
                    }
                for(int x: c[i])
                    pos[x] = -1;
            }
end:
        puts(human ? "Human" : "Robot");
    }
}