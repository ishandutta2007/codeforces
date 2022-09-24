#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <deque>
#include <math.h>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
#include <random>
using namespace std;

using namespace std;
typedef long long ll;
vector<string> inp;
#define pb push_back
set <string> grumpy = {"no", "donteven", "godieinahole", "terrible", "areyouserious", "worse"};
set <string> normal = {"cool", "great", "notbad", "idontthinkso"};
int cnt1 = 0;
int cnt2 = 0;
int main()
{
    srand(time(0));
    int a;
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        string s;
        cin >> s >> s;
        if(s == "hard") cnt1++;
        else cnt2++;
    }
    for(int i = 1;; i++)
    {
        ll p = (i * i) / 2;
        int k = i * i - p;
        if(p >= cnt1 && k >= cnt2)
        {
            cout << i << "\n";
            return 0;
        }
        if(k >= cnt1 && p >= cnt2)
        {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}