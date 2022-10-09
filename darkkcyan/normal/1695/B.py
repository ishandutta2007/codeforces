def main():
    for testcase in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        
        if n % 2 == 1:
            print("Mike")
            continue
        
        min_val = [(a[0], 0), (a[1], 1)]
        for i in range(2, n):
            min_val[i % 2] = min(min_val[i % 2], (a[i], i))
        
        if min_val[0][0] < min_val[1][0]:
            print("Joe")
        elif min_val[0][0] > min_val[1][0]:
            print("Mike")
        elif min_val[0][1] < min_val[1][1]:
            print("Joe")
        else:
            print("Mike")
main()