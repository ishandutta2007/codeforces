#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n, ai, bi;
vector<int> answer;
vector<vector<int > > kv;
vector<int> poshli(vector<int> ll){
    fflush(stdout);
    int siz = ll.size();
    cout << siz << endl;
    fflush(stdout);
    for (int i=0;i<siz;i++){
        cout << ll[i] << " ";
    }
    cout << endl;
    fflush(stdout);
    vector<int> hh;
    int vv;
    for (int i=0;i<n;i++){
        cin >> vv;
        hh.push_back(vv);
    }
    fflush(stdout);
    return hh;
}
int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        answer.push_back(1000000000);
    }
    vector<int> help;
    help.push_back(1);
    help.push_back(n);
    kv.push_back(help);
    int max_length = n;
    while (max_length > 1){
        max_length = 0;
        vector<int> z1;
        vector<int> z2;
        vector<vector<int > > smena;
        for (int i=0;i<kv.size();i++){
            int x1 = kv[i][0];
            int razmer = kv[i][1];
            if (razmer % 2 == 0){
            for (int j=0;j<razmer/2;j++){
                z1.push_back(x1 + j);
                z2.push_back(x1 + razmer - j - 1);
            }
            }
            else{
                    for (int j=0;j<=razmer/2;j++){
                z2.push_back(x1 + razmer - j - 1);
                        }
                for (int j=0;j<razmer/2;j++){
                z1.push_back(x1 + j);
                        }

            }
        }
        vector<int> answer1 = poshli(z1);
        vector<int> answer2 = poshli(z2);
        for (int i=0;i<kv.size();i++){
            int x1 = kv[i][0];
            int razmer = kv[i][1];
            if (razmer % 2 == 0){
                for (int j=0;j<razmer/2;j++){
                    answer[x1 + razmer - 2 - j] = min(answer[x1 + razmer - 2 - j], answer1[x1 + razmer - 2 - j]);
                }
                for (int j=0;j<razmer/2;j++){
                    answer[x1 + j - 1] = min(answer[x1 + j - 1], answer2[x1 + j - 1]);
                }
                vector<int> h1;
                h1.push_back(x1);
                h1.push_back(razmer / 2);
                vector<int> h2;
                h2.push_back(x1 + razmer / 2);
                h2.push_back(razmer / 2);
                smena.push_back(h1);
                smena.push_back(h2);
                max_length = max(max_length, razmer / 2);
            }
            else{
                for (int j=0;j<=razmer/2;j++){
                    answer[x1 + razmer - 2 - j] = min(answer[x1 + razmer - 2 - j], answer1[x1 + razmer - 2 - j]);
                }
                for (int j=0;j<razmer/2;j++){
                    answer[x1 + j - 1] = min(answer[x1 + j - 1], answer2[x1 + j - 1]);
                }
                if (razmer == 3){
                    vector<int> h1;
                    h1.push_back(x1 + 1);
                    h1.push_back(2);
                    smena.push_back(h1);
                    max_length = max(max_length, 2);
                }
                else{
                vector<int> h1;
                h1.push_back(x1);
                h1.push_back(razmer / 2);
                vector<int> h2;
                h2.push_back(x1 + razmer / 2);
                h2.push_back(razmer - razmer / 2);
                smena.push_back(h1);
                smena.push_back(h2);
                max_length = max(max_length, razmer - razmer / 2);
                }
            }
        }
        kv = smena;
    }
    cout << -1 << endl;
    fflush(stdout);
    for (int i=0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
    fflush(stdout);
    return 0;
}