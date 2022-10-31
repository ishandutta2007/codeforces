#include <iostream>
main(){int n, k, i; std::cin >> n >> k;for(i = 1; i<=n && (k+=5*i)<=240; ++i);std::cout << i-1 << '\n';}