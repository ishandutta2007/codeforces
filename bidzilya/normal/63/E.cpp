#include <iostream>
#include <cmath>
using namespace std;

const int N = 1<<18+1;
const int nx[3][19] = {{3, 4, 5, 7, 8, 9, 10, -1, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1},
                       {4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1, -1},
                       {1, 2, -1, 4, 5, 6, -1, 8, 9, 10, 11, -1, 13, 14, 15, -1, 17, 18, -1}};

bool ans[N], found[N];

int bit(int x, int num)
{
    return ((x >> num)&1);
}

bool win(int x)
{
    if (found[x])return ans[x];
    found[x] = true;
    ans[x] = false;
    for (int i=0; i<19; i++)
        for (int j=0; j<3; j++)
            for (int k=i, dx=0; k!=-1; k=nx[j][k])
            {
                if (!bit(x,k))break;
                dx += (1 << k);
                ans[x] |= (!win(x-dx));
            }
    return ans[x];
}

int main()
{
    int x = 0;
    for (int i=0; i<19; i++)
    {
        string s;
        cin >> s;
        if (s == "O") x += (1 << i);
    }
    for (int i=0; i<N; i++) found[i] = false;
    if (win(x))cout << "Karlsson";
        else   cout << "Lillebror";
    cout << endl;
    return 0;
}