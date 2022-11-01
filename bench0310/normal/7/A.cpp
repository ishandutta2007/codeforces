#include <iostream>

using namespace std;

int main()
{
    string s[8];
    for(int i=0;i<8;i++) cin >> s[i];
    int cnt=0;
    for(int o=0;o<8;o++)
    {
        bool good=1;
        for(int i=0;i<8;i++)
        {
            if(s[o][i]=='W')
            {
                good=0;
                break;
            }
        }
        cnt+=good;
    }
    for(int o=0;o<8;o++)
    {
        bool good=1;
        for(int i=0;i<8;i++)
        {
            if(s[i][o]=='W')
            {
                good=0;
                break;
            }
        }
        cnt+=good;
    }
    if(cnt==16) cnt=8;
    cout << cnt << endl;
    return 0;
}