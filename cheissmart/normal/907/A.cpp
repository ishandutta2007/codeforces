#include <iostream>

using namespace std;

int main()
{
    int v1, v2, v3, vm;
    bool flag = true;
    cin >> v1 >> v2 >> v3 >> vm;
    for(int b1=v1;b1<=2*v1 && flag;b1++)
    for(int b2=v2;b2<=min(b1-1,2*v2) && flag;b2++)
    for(int b3=v3;b3<=min(b2-1,2*v3) && flag;b3++){
        if(vm>b1) continue;
        if(vm>b2) continue;
        if(vm>b3) continue;
        if(vm<=b1 && b1<=2*vm) continue;
        if(vm<=b2 && b2<=2*vm) continue;
        if(vm<=b3 && b3<=2*vm){
            flag = false;
            cout << b1 << endl << b2 << endl << b3 << endl;
            break;
        }
    }
    if(flag) cout << -1 << endl;
}