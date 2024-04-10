#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> a1;
    vector<int> a2;
    int n, m;
    cin >> n >> m;
    map <int, vector<int> > mymap;
    int inp;
    vector<int> help;
    for (int i=0;i<n;i++){
        cin >> inp;
        a2.push_back(0);
        mymap[inp].push_back(i);
    }
    vector<vector<int> > roz;
    for (int i=0;i<m;i++){
        vector<int> a;
        a1.push_back(0);
        cin >> inp;
        a.push_back(inp);
        a.push_back(i);
        roz.push_back(a);
    }
    sort(roz.begin(), roz.end());
    int computers = 0;
    int per = 0;
    for (int i=0;i<m;i++){
        int counter = 0;
        int rozetka = roz[i][0];
        bool res = false;
        while (rozetka > 1){
            if (mymap.count(rozetka) == 1){
                a1[roz[i][1]] = counter;
                computers ++;
                per += counter;
                if (mymap[rozetka].size() == 1){
                    a2[mymap[rozetka].front()] = roz[i][1] + 1;
                    mymap.erase(rozetka);
                }
                else{
                    int answer = mymap[rozetka].back();
                    mymap[rozetka].pop_back();
                    a2[answer] = roz[i][1] + 1;
                }
                rozetka = 1;
                res = true;
            }
            else{
                counter ++;
                if (rozetka % 2 == 0){
                    rozetka = rozetka / 2;
                }
                else{
                    rozetka = rozetka / 2 + 1;
                }
            }
        }
        if (res == false){
            if (mymap.count(1) == 1){
                computers ++;
                per += counter;
                a1[roz[i][1]] = counter;
                if (mymap[1].size() == 1){
                    a2[mymap[1].front()] = roz[i][1] + 1;
                    mymap.erase(1);
                }
                else{
                    int answer = mymap[1].back();
                    mymap[1].pop_back();
                    a2[answer] = roz[i][1] + 1;
                }
            }
        }

    }
    cout << computers << " " << per << endl;
    for (int i=0;i<a1.size() - 1;i++){
        cout << a1[i] << " ";
    }
    cout << a1[a1.size()-1] << endl;
    for (int i=0;i<a2.size() - 1;i++){
        cout << a2[i] << " ";
    }
    cout << a2[a2.size()-1] << endl;

}