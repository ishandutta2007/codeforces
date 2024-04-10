def main():
    n = input().replace("4", "0").replace("7", "1")
    answer = (1<<(len(n)))-1
    answer += int(n, 2)

    print(answer)
    
main()