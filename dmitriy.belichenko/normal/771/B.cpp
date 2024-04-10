#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
long long n , k;
vector < vector<long long> > d;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    }


int main()
{
    cin >> n >> k;
    vector<int> cl(n);
    cl[0] = 0;

    vector<string> s(n - k +1);
    for(int i = 0; i < n - k + 1; i++)
    {
        cin >> s[i];
        
    }
    for(int i = 0; i < n; i++) cl[i] = i;
        int mx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == "NO")
        {
            cl[i + k - 1] = cl[i];
        }
        //else cl[i] = mx;
        mx++;
        
    }
    char ans[51];
    for(int i = 0; i < 26; i++) ans[i] = char(int('A') + i);
    char as[51];
    for(int i = 0; i < 26; i++) as[i] = char(int('a') + i);

    for(int i = 0; i < n; i++) if(cl[i] < 26) cout << ans[cl[i]] << " ";
    else cout << ans[cl[i] % 26] << as[cl[i] % 26] << " ";
    
 }