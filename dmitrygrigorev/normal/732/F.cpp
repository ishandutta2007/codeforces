#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;
    vector<vector<vector<int> > >data;
    vector <vector< int > > inp;
    vector <int> fup;
    vector<int> tin;
    vector<bool> used;
    vector<bool> lm;
    vector <int> comp;
    vector <bool> men;
    vector<bool> ur;
    int coun;
    int timer;
void dfs(int vertex, int last){
    used[vertex] = true;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i][0];
        if (to == last){
            continue;
        }
        if (ur[data[vertex][i][1]] == true){
            continue;
        }
        if(used[to]){
            int rebro = data[vertex][i][1];
            if (ur[rebro] == false){
                ur[rebro] = true;
                if (inp[rebro][0] - 1 != vertex){
                    men[rebro] = true;
                }
            }
        }
        else{
            int rebro = data[vertex][i][1];
            if (lm[rebro] == true){
                if (inp[rebro][1] - 1 != vertex){
                    men[rebro] = true;
                }
            }
            else{
                if (inp[rebro][0] - 1 != vertex){
                    men[rebro] = true;
                }
            }
            ur[rebro] = true;
        dfs(to, vertex);
        }

}
}
void razbivka(int vertex, int last, int counter){
    comp[vertex] = counter;
    used[vertex] = true;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i][0];
        if (to==last | used[to]){
            continue;
        }
        if (lm[data[vertex][i][1]]){
                coun ++;
            razbivka(to, vertex, coun);
        }
        else{
            razbivka(to, vertex, counter);
        }
    }
}
void most(int vertex, int last){
    timer ++;
    used[vertex] = true;
    tin[vertex] = timer;
    fup[vertex] = timer;
    for (int i=0; i<data[vertex].size();i++){
        int to = data[vertex][i][0];
        if (to==last){
            continue;
        }
        if (used[to]){
            fup[vertex] = min(fup[vertex], tin[to]);
        }
        else{
            most(to, vertex);
            fup[vertex] = min(fup[vertex], fup[to]);
            if (tin[vertex] < fup[to]){
                lm[data[vertex][i][1]] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    timer = 0;
    for (int i=0;i<n;i++){
        vector<vector<int> > help;
        data.push_back(help);
        tin.push_back(0);
        fup.push_back(0);
        comp.push_back(0);
        used.push_back(false);
    }
    int a, b;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        men.push_back(false);
        ur.push_back(false);
        vector<int> first;
        vector<int> second;
        second.push_back(a - 1);
        second.push_back(i);
        first.push_back(b-1);
        first.push_back(i);
        data[a - 1].push_back(first);
        data[b - 1].push_back(second);
        vector<int> j;
        j.push_back(a);
        j.push_back(b);
        inp.push_back(j);
        lm.push_back(false);
    }
    most(0, -1);
    for (int i=0;i<n;i++){
        used[i] = false;
    }
    coun = 0;
    razbivka(0, -1, 0);
    map <int, int> mymap;
    int maximum = 0;
    int max_c;
    for (int i=0;i<n;i++){
        int element = comp[i];
        if (mymap.count(element) == 0){
            mymap[element] = 1;
            if (maximum == 0){
                maximum = 1;
                max_c = element;
            }
        }
        else{
            mymap[element] = mymap[element] + 1;
            if (mymap[element] > maximum){
                maximum = mymap[element];
                max_c = element;
            }
        }
    }
    for (int i=0;i<n;i++){
        used[i] = false;
    }
    for (int i=0;i<n;i++){
        if (comp[i] == max_c){
            dfs(i, -1);
            break;
        }
    }
    cout << maximum << endl;
    for (int i=0;i<m;i++){
        if (men[i] == false){
            cout << inp[i][0] << " " << inp[i][1] << endl;
        }
        else{
            cout << inp[i][1] << " " << inp[i][0] << endl;
        }
    }
}