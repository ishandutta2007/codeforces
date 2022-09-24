check = [i for i in range(1,100000) if str(i)[-1] != '3' and i % 3 > 0]
for i in range(int(input())):
    print(check [int(input())-1])