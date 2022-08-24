#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    vector<vector<int> >data;

int main()
{
    int obj = 0;
    int n;
    int ind;
    cin >> n;
    int a, b, c;
    for (int i=0; i<n;i++){
        cin >> a >> b >> c;
        vector<int> help;
        help.push_back(a);
        help.push_back(b);
        help.push_back(c);
        sort(help.rbegin(), help.rend());
        help.push_back(i + 1);
        data.push_back(help);
        if (help[2] > obj){
            ind = i + 1;
            obj = help[2];
        }
    }
    sort(data.begin(), data.end());
    int m = 0;
    int i1, i2;
    for (int i=1;i<data.size();i++){
        if (data[i][0] == data[i - 1][0] & data[i][1] == data[i - 1][1]){
            int r = min(data[i][2] + data[i - 1][2], data[i][1]);
            if ((r) > m){
                m = r;
                i1 = data[i][3];
                i2 = data[i - 1][3];
            }
        }
    }
    if (m > obj){
        cout << 2 << endl;
        cout << i1 << " " << i2 << endl;
    }
    else{
        cout << 1 << endl;
        cout << ind << endl;
    }
    return 0;
}