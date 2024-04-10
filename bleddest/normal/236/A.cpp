#include<string>
#include<iostream>
#include<set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for(char c = 'a'; c <= 'z'; c++)
    {
        /*for(auto x : s)
            if(c == x)
            {
                cnt++;
                break;
            }*/
        if(s.find(c) != string::npos)
            cnt++;
    }                
    if(cnt % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {                                    
        cout << "IGNORE HIM!" << endl;
    }
}