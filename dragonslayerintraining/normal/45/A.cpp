#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> months;

int main(){
  months.push_back("January");
  months.push_back("February");
  months.push_back("March");
  months.push_back("April");
  months.push_back("May");
  months.push_back("June");
  months.push_back("July");
  months.push_back("August");
  months.push_back("September");
  months.push_back("October");
  months.push_back("November");
  months.push_back("December");
  std::string M;
  int K;
  std::cin>>M>>K;
  std::cout<<months[(std::find(months.begin(),months.end(),M)-months.begin()+K)%12]<<std::endl;
  return 0;
}