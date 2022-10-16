//  228

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tComputer
{
    int speed, ram, hdd, price, index;
    bool operator <(const tComputer & playerObj) const
    {
        return price < playerObj.price;
    }
};

int main()
{
    int n;
    cin >> n;
    vector <tComputer> v(n);

    while(n--)
    {
        tComputer aux;
        cin >> aux.speed >> aux.ram >> aux.hdd >> aux.price;
        aux.index = v.size()-n;
        v[v.size()-n -1] = aux;
    }

    sort(v.begin(), v.end());//Ordenar por precio

    int i = 0, min = -1;
    tComputer best = v[0];
    bool found = false;
    while(i < v.size() && !found)
    {
        bool outdated = false;
        for(int j = i; j < v.size() && !outdated;j++)
        {
            if(v[i].speed < v[j].speed && v[i].ram < v[j].ram && v[i].hdd < v[j].hdd)
                outdated = true;
        }

        if(!outdated)
        {
            found = true;
            min = v[i].index;
        }

        i++;
    }

    cout << min << '\n';

}