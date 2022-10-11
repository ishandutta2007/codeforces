import sys
n = int(sys.stdin.readline())
arr = sys.stdin.readline().split()

bad = "1"
cnt_zero = 0
good_st = "1" + "0" * 100000


for i in range(n):
    if arr[i] == "0":
        sys.stdout.write("0")
        exit(0)
    if arr[i] == good_st[:len(arr[i])]:
        cnt_zero += len(arr[i]) - 1
    else:
        bad = arr[i]
            

sys.stdout.write(bad + "0" * cnt_zero)