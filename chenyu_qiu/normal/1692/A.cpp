#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        int a,b,c,d;
        int count = 0;
        cin >> a >> b >> c >> d;
        if(a < b)count++;
        if(a < c)count++;
        if(a < d)count++;
        std::cout << count << std::endl;
    }
    return 0;
}