#import numpy as np

for tc in range(int(input())):
    n = int(input())
    print(1 ^ (sum(map(int, input().split())) % n == 0))