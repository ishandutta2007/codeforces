#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int price, height;
} thing;
bool comp_price(thing a, thing b)
{
    return a.price < b.price;
}

bool comp(thing *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i].height < arr[i - 1].height)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    thing *arr = new thing[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].price >> arr[i].height;
    }
    sort(arr, arr + n, comp_price);
    if (comp(arr, n))
    {
        cout << "Happy Alex" << endl;
    }
    else
    {
        cout << "Poor Alex" << endl;
    }
    return 0;
}