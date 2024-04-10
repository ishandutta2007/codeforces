#include <iostream>

using namespace std;
int da, db;

int main()
{
    cin >> da >> db;
    if(da==db)
    {
        cout << da*10+1 << ' ' << da*10+2;
        return 0;
    }
    if(db==da+1)
    {
        cout << da << ' ' << db;
        return 0;
    }
    if(da==9 && db==1)
    {
        cout << "9 10";
        return 0;
    }
    cout << -1;
    return 0;
}