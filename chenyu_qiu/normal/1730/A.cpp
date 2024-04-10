#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        
        int numstring;
        cin >> numstring;
        int a[numstring];
        int count[110];
        int secondcost;
        int totalcost = 0;
        cin >> secondcost;
    
        // count
        for (int i = 0; i < 110; i++) {
            count[i] = 0;
        }
        
        // 
        for (int i = 0; i < numstring; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < numstring; i++) {
            count[a[i] - 1]++;
        }
        
        for (int i = 0; i < 110; i++) {
            if(count[i] >= secondcost)
            {
                totalcost += secondcost;
            
            }
            else
            {
                totalcost += count[i];
            
            }
        }
        
    std::cout << totalcost << std::endl;
    
    }
    
    return 0;
}