#include<iostream>
int main()
{
    int n;
    std::cin>>n;
    if(n<=50000)
        std::cout<<3<<std::endl;
    else if(n>=54000)
        std::cout<<1<<std::endl;
    else
        std::cout<<2<<std::endl;
    return 0;
}