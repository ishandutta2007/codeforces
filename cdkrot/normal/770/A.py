#!/usr/bin/python3
n,k = map(int,input().split())
print(''.join([chr(ord('a')+(i%k)) for i in range(n)]))