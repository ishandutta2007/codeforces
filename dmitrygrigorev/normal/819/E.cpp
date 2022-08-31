#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define D double
using namespace std;
vector<vector<int> > ans;
void get(int n){
    if (n==3){
        vector<int> h; h.push_back(1); h.push_back(2); h.push_back(3);
        ans.push_back(h); ans.push_back(h);
        return;
    }
    if (n==4){
        vector<int> h1, h2, h3, h4;
        h1.push_back(1); h1.push_back(2); h1.push_back(3);
        h2.push_back(1); h2.push_back(2); h2.push_back(4);
        h3.push_back(4); h3.push_back(1); h3.push_back(3);
        h4.push_back(4); h4.push_back(2); h4.push_back(3);
        ans.push_back(h1); ans.push_back(h2); ans.push_back(h3); ans.push_back(h4);
        return;
    }
    if (n % 2 == 0){
        for (int i=n-2;i>0;i-=2){
            vector<int> help; help.push_back(n); help.push_back(i); help.push_back(n-1); help.push_back(i-1);
            ans.push_back(help);
            if (i > 2) ans.push_back(help);
        }
        vector<int> h1, h2;
        h1.push_back(n); h1.push_back(n-1); h1.push_back(1);
        h2.push_back(n); h2.push_back(n-1); h2.push_back(2);
        ans.push_back(h1); ans.push_back(h2);
    }
    else{
        for (int i=n-2;i>1;i-=2){
            vector<int> help; help.push_back(n); help.push_back(i); help.push_back(n-1); help.push_back(i-1);
            ans.push_back(help);
            ans.push_back(help);
        }
        vector<int> h1, h2;
        h1.push_back(n); h1.push_back(n-1); h1.push_back(1);
        h2.push_back(1); h2.push_back(n); h2.push_back(n-1);
        ans.push_back(h1); ans.push_back(h2);
    }
    get(n-2);
}
int32_t main()
{
    int n;
    cin >> n;
    get(n);
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++){
        cout << ans[i].size() << " ";
        for (int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
;