#include <iostream>

using namespace std;

int main()
{
    string s;
    int num=0,res=0;
    while(getline(cin,s))
    {
        if(s[0]=='+') num++;
        else if(s[0]=='-') num--;
        else
        {
            int idx=1;
            while(s[idx-1]!=':') idx++;
            res+=num*((int)s.size()-idx);
        }
    }
    cout << res << endl;
    return 0;
}