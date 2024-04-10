#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        int sum = 0;
        std::cin >> num;
        int a[num + 1];
        int min = 0;
        for (int j = 0; j < num; j++) {
            cin >> a[j];
        }
        
        for(int j = 0 ; j < num; j++){
		if(a[j] < a[min])
			min = j;
	    }
	    int minnum = a[min];
	    for (int j = 0; j < num; j++) {
	        int temp = a[j] - minnum;
	        sum = sum + temp;
	}
	    std::cout << sum << std::endl;
	    
	
    }
    return 0;
}